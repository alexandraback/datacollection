from multiprocessing import Pool
import os
import fractions
import math

def solvePuzzle(strings):
    modval=1000000007
    compressedStrings = compressStrings(strings)
    if not preTest(strings, compressedStrings):
        return 0

    doublemap={}
    i=0
    forbiddenChars=set()
    while i<len(compressedStrings):
        if compressedStrings[i][0]==compressedStrings[i][-1]:
            doubleChar=compressedStrings[i][0]
            if doubleChar in list(doublemap.keys()):
                doublemap[doubleChar]+=1
            else:
                doublemap[doubleChar]=1
            del compressedStrings[i]
            i-=1
        i+=1
    #    testChar = compressedStrings[i][-1]
    #    if testChar == compressedStrings[i][0]:
    #        found=False
    #        for j in range(i+1,len(compressedStrings)):
    #            if i!=j and compressedStrings[j]==compressedStrings[i]:
    #                doubleChar=compressedStrings[j][0]
    #                if doubleChar in list(doublemap.keys()):
    #                    doublemap[doubleChar]+=1
    #                else:
    #                    doublemap[doubleChar]=2
    #                del compressedStrings[i]
    #                i-=1
    #                Found=True
    #                break
    #        if not found:
    #            doublestrings+=[compressedStrings[i]]
    #            del compressedStrings[i]
    #            i-=1
    #    i+=1

    compressedStrings=[key+key for key in doublemap.keys()]+compressedStrings
                    
    i=0
    while i<len(compressedStrings):
        testChar = compressedStrings[i][-1]
        for j in range(0,len(compressedStrings)):
            if i!=j and compressedStrings[j][0]==testChar:
                if compressedStrings[i][0]!=compressedStrings[i][-1] and compressedStrings[j][0]!=compressedStrings[j][-1]:
                    if compressedStrings[j][-1]==compressedStrings[i][0]:
                        return 0
                    if compressedStrings[j][0] in forbiddenChars:
                        return 0
                    forbiddenChars.add(compressedStrings[j][0])
                compressedStrings[j]=compressedStrings[i][0]+compressedStrings[j][-1]
                del compressedStrings[i]
                i-=1
                break
        i+=1

    for testString in compressedStrings:
        for testChar in forbiddenChars:
            if testChar in testString:
                return 0

    for i in range(0,len(compressedStrings)):
        for j in range(0,len(compressedStrings)):
          if i!=j:
            if compressedStrings[i][0]==compressedStrings[j][0] or compressedStrings[i][-1]==compressedStrings[j][-1]:
                return 0

    result=math.factorial(len(compressedStrings))%modval

    for key in doublemap.keys():
        result=(result*math.factorial(doublemap[key]))%modval
        
    return result
        

def compressStrings(startList):
    ret=[]
    for i in startList:
        if len(i)==1:
            ret+=[i+i]
        else:
            ret+=[i[0]+i[-1]]
    return ret

def preTest(startList, compressedList):
   for testString in startList:
       forbidden=set()
       forbidden.add(testString[0])
       for i in range(1,len(testString)):
         if testString[i]!=testString[i-1]:
            if testString[i] in forbidden:
                return False
            forbidden.add(testString[i])
      
   for i in range(0,len(startList)):
       for j in range(0, len(compressedList)):
            if i!=j:
                for c in startList[i]:
                    if c in startList[j] and c not in compressedList[j]:
                        return False
   return True
    
    

input_text = open("input.in")
lines = input_text.readlines()
input_text.close()
currentLine=1
with open("output", "a") as outputfile:
    pool = Pool(processes=6)
    results = {}
    for num in range(0,int(lines[0])):
        cars=lines[num*2+2][0:-1].split(" ")
        results[num]= solvePuzzle(cars)
        #results[num]= pool.apply_async(solvePuzzle, [cars])
    for num in range(0,int(lines[0])):
        #outputfile.write("Case #"+str(num+1)+": "+str(results[num].get())+"\n")
        outputfile.write("Case #"+str(num+1)+": "+str(results[num])+"\n")
