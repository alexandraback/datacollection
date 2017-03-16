# when input is too large
#f = open("txt","r")
#def input():
#   return f.readline().strip()

def solve(scA,scB):
    realA = ""
    realB = ""
    larger = 0
    for s in range(len(scA)):
        curA = scA[s]
        curB = scB[s]
        if curA == "?" and curB == "?":
            if larger == 1:
                realA += "0"
                realB += "9"
            elif larger == -1:
                realA += "9"
                realB += "0"
            else:
                if s+1 <len(scA):
                    if scA[s+1] == "?" and scB[s+1] == "?":
                        realA += "0"
                        realB += "0"
                    else:
                        allequal = True
                        for i in range(len(scA)-s-1):
                            #print(list(range(len(scA)-s-1)))
                            if scA[s+1+i] != "?" and scB[s+1+i] != "?" and scA[s+1+i]!= scB[s+1+i]:
                                allequal = False
                        if allequal:
                            realA += "0"
                            realB += "0"
                        else:
                            maxA = scA[s+1:]
                            maxB = scB[s+1:]
                            minA = scA[s+1:]
                            minB = scB[s+1:]
                            maxA = maxA.replace("?","9")
                            maxB = maxB.replace("?","9")
                            minA = minA.replace("?","0")
                            minB = minB.replace("?","0")
                            if not maxA:
                                maxA = 0
                                maxB = 0
                                minA = 0
                                minB = 0
                            sub1 = abs(int(minA)-int(maxB))
                            sub2 = abs(int(minA)-int(minB))
                            sub7 = abs(int(maxA)-int(minB))
                            sub8 = abs(int(maxA)-int(maxB))
                            sub3 = abs(10**(len(scA)-s-1)+int(minA)-int(maxB))#?0? ?9? 10
                            sub4 = abs(10**(len(scA)-s-1)+int(maxA)-int(minB))#?0? ?9? 10
                            sub5 = abs(int(minA)-int(maxB)-10**(len(scA)-s-1))#?9? ?0? 01
                            sub6 = abs(int(maxA)-int(minB)-10**(len(scA)-s-1))#?9? ?0? 01
                            #print(sub1)
                            #print(sub2)
                            #print(sub3)
                            #print(sub4)
                            minO = min(sub1,sub2,sub3,sub4,sub5,sub6,sub7,sub8)
                            if minO == sub1:
                                realA += "0"
                                realB += "0"
                            elif minO == sub2:
                                realA += "0"
                                realB += "0"
                            elif minO == sub7:
                                realA += "0"
                                realB += "0"
                            elif minO == sub8:
                                realA += "0"
                                realB += "0"
                            elif minO == sub3:
                                realA += "1"
                                realB += "0"
                                larger = 1
                            elif minO == sub4:
                                realA += "1"
                                realB += "0"
                                larger = 1
                            elif minO == sub5:
                                realA += "0"
                                realB += "1"
                                larger = -1
                            else:
                                realA += "0"
                                realB += "1"
                                larger = -1
                else:
                    realA += "0"
                    realB += "0"
        elif curA == "?" and curB !="?":
            if larger == 1:
                realA += "0"
                realB += curB
            elif larger == -1:
                realA += "9"
                realB += curB
            else:
                if s+1 <len(scA):
                    allequal = True
                    for i in range(len(scA)-s-1):
                        #print(list(range(len(scA)-s-1)))
                        if scA[s+1+i] != "?" and scB[s+1+i] != "?" and scA[s+1+i]!= scB[s+1+i]:
                            allequal = False
                    if allequal:
                        realA += curB
                        realB += curB
                    else:
                        maxA = scA[s+1:]
                        maxB = scB[s+1:]
                        minA = scA[s+1:]
                        minB = scB[s+1:]
                        maxA = maxA.replace("?","9")
                        maxB = maxB.replace("?","9")
                        minA = minA.replace("?","0")
                        minB = minB.replace("?","0")
                        if not maxA:
                            maxA = 0
                            maxB = 0
                            minA = 0
                            minB = 0
                        sub1 = abs(int(minA)-int(maxB))#?3? ?2? 00
                        sub2 = abs(int(maxA)-int(minB))#?2? ?3? 00
                        sub7 = abs(int(maxA)-int(minB))
                        sub8 = abs(int(maxA)-int(maxB))
                        if curB!="9":
                            sub3 = abs(10**(len(scA)-s-1)+int(minA)-int(maxB))#?0? ?9? 10
                            sub4 = abs(10**(len(scA)-s-1)+int(maxA)-int(minB))#?0? ?9? 10
                        else:
                            sub3 = 99999999999999999999
                            sub4 = 99999999999999999999
                        sub5 = abs(int(minA)-int(maxB)-10**(len(scA)-s-1))#?9? ?0? 01
                        sub6 = abs(int(maxA)-int(minB)-10**(len(scA)-s-1))#?9? ?0? 01
                        minO = min(sub1,sub2,sub3,sub4,sub5,sub6,sub7,sub8)
                        if minO == sub5:
                            realA += str(int(curB)-1)
                            realB += curB
                            larger = -1
                        elif minO == sub6:
                            realA += str(int(curB)-1)
                            realB += curB
                            larger = -1
                        elif minO == sub1:
                            realA += curB
                            realB += curB
                        elif minO == sub2:
                            realA += curB
                            realB += curB
                        elif minO == sub7:
                            realA += curB
                            realB += curB
                        elif minO == sub8:
                            realA += curB
                            realB += curB
                        elif minO == sub3:
                            realA += str(int(curB)+1)
                            realB += curB
                            larger = 1
                        else:
                            realA += str(int(curB)+1)
                            realB += curB
                            larger = 1
                        
                else:
                    realA += curB
                    realB += curB
        elif curA != "?" and curB == "?":
            if larger == 1:
                realA += curA
                realB += "9"
            elif larger == -1:
                realA += curA
                realB += "0"
            else:
                if s+1 <len(scA):
                    allequal = True
                    for i in range(len(scA)-s-1):
                        #print(list(range(len(scA)-s-1)))
                        if scA[s+1+i] != "?" and scB[s+1+i] != "?" and scA[s+1+i]!= scB[s+1+i]:
                            allequal = False
                    if allequal:
                        realA += curA
                        realB += curA
                    else:
                        maxA = scA[s+1:]
                        maxB = scB[s+1:]
                        minA = scA[s+1:]
                        minB = scB[s+1:]
                        maxA = maxA.replace("?","9")
                        maxB = maxB.replace("?","9")
                        minA = minA.replace("?","0")
                        minB = minB.replace("?","0")
                        if not maxA:
                            maxA = 0
                            maxB = 0
                            minA = 0
                            minB = 0
                        sub1 = abs(int(minA)-int(maxB))#?3? ?2? 00
                        sub2 = abs(int(maxA)-int(minB))#?2? ?3? 00
                        sub7 = abs(int(maxA)-int(minB))
                        sub8 = abs(int(maxA)-int(maxB))
                        sub3 = abs(10**(len(scA)-s-1)+int(minA)-int(maxB))#?0? ?9? 10
                        sub4 = abs(10**(len(scA)-s-1)+int(maxA)-int(minB))#?0? ?9? 10
                        if curA != "9":
                            sub5 = abs(int(minA)-int(maxB)-10**(len(scA)-s-1))#?9? ?0? 01
                            sub6 = abs(int(maxA)-int(minB)-10**(len(scA)-s-1))#?9? ?0? 01
                        else:
                            sub5 = 99999999999999999999
                            sub6 = 99999999999999999999
                        #print(sub1)
                        #print(sub2)
                        #print(sub3)
                        #print(sub4)
                        minO = min(sub1,sub2,sub3,sub4,sub5,sub6,sub7,sub8)
                        if minO == sub3:
                            realA += curA
                            realB += str(int(curA)-1)
                            larger = 1
                        elif minO == sub4:
                            realA += curA
                            realB += str(int(curA)-1)
                            larger = 1
                        elif minO == sub1:
                            realA += curA
                            realB += curA
                        elif minO == sub2:
                            realA += curA
                            realB += curA
                        elif minO == sub7:
                            realA += curA
                            realB += curA
                        elif minO == sub8:
                            realA += curA
                            realB += curA
                        elif minO == sub5:
                            realA += curA
                            realB += str(int(curA)+1)
                            larger = -1
                        else:
                            realA += curA
                            realB += str(int(curA)+1)
                            larger = -1
                else:
                    realA += curA
                    realB += curA

        else:
            realA += curA
            realB += curB
            if larger==0:
                if int(curA) > int(curB):
                    larger = 1
                elif int(curB) > int(curA):
                    larger = -1
                else:
                    larger = 0
    return realA+" "+realB

T = int(input())
O = []

for index in range(T):
    scA,scB = map(str, input().split())
    O.append("Case #"+str(index+1)+": "+str(solve(scA,scB)))

for o in O:
    print(o)

