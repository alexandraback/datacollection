SAME = 0
BIGGER = 1
SMALLER = 2

ansset = [-1, "0", "0"]

def isbetter(newset):
    global ansset
    #print ansset, newset
    if newset[0] >= 0:
        if ansset[0] == -1:
            ansset = newset
        else:
            if ansset[0] > newset[0]:
                ansset = newset
            elif ansset[0] == newset[0]:
                if int(ansset[1]) > int(newset[1]):
                    ansset = newset
                elif int(ansset[1]) == int(newset[1]):
                    if int(ansset[2]) > int(newset[2]):
                        ansset = newset

#set first bigger  
def tryset_1(list1,list2):
    templist1 = list1[:]
    templist2 = list2[:]
    for i in range(len(templist1)):
        if templist1[i] == '?':
            templist1[i] = '0'
    for i in range(len(templist2)):
        if templist2[i] == '?':
            templist2[i] = '9'
    firstnum = "".join(templist1)
    secondnum = "".join(templist2)
    isbetter([int(firstnum) - int(secondnum), firstnum,secondnum])

#set second bigger  
def tryset_2(list1,list2):
    templist1 = list1[:]
    templist2 = list2[:]
    for i in range(len(templist1)):
        if templist1[i] == '?':
            templist1[i] = '9'
    for i in range(len(templist2)):
        if templist2[i] == '?':
            templist2[i] = '0'
    firstnum = "".join(templist1)
    secondnum = "".join(templist2)
    isbetter([int(secondnum) - int(firstnum), firstnum,secondnum])

def run(line):
    global ansset
    ansset = [-1, "0", "0"]
    origstr1 = line.split()[0]
    origstr2 = line.split()[1]
    str1 = list(origstr1)
    str2 = list(origstr2)

    length = len(str1)
    for i in range(length):
        if str1[i] == '?':
            if str2[i] == '?':
                #try first bigger
                str1[i] = '0'
                str2[i] = '0'
                tryset_1(str1,str2)
                str1[i] = '1'
                str2[i] = '0'
                tryset_1(str1,str2)
                #try second bigger
                str1[i] = '0'
                str2[i] = '0'
                tryset_2(str1,str2)
                str1[i] = '0'
                str2[i] = '1'
                tryset_2(str1,str2)
                str1[i] = '0'
                str2[i] = '0'
            else:
                #try first bigger
                str1[i] = str2[i]
                tryset_1(str1,str2)
                if str2[i] != '9':
                    str1[i] = str(int(str2[i])+1)
                    tryset_1(str1,str2)
                #try second bigger
                str1[i] = str2[i]
                tryset_2(str1,str2)
                if str2[i] != '0':
                    str1[i] = str(int(str2[i])-1)
                    tryset_2(str1,str2)
                str1[i] = str2[i]
        else:
            if str2[i] == '?':
                #try first bigger
                str2[i] = str1[i]
                tryset_1(str1,str2)
                if str1[i] != '0':
                    str2[i] = str(int(str1[i])-1)
                    tryset_1(str1,str2)
                #try second bigger
                str2[i] = str1[i]
                tryset_2(str1,str2)
                if str1[i] != '9':
                    str2[i] = str(int(str1[i])+1)
                    tryset_2(str1,str2)
                str2[i] = str1[i]
            else:
                tryset_1(str1,str2)
                tryset_2(str1,str2)
    print "Finish!"
    return ansset[1] + " " + ansset[2]

fi = open("B-small-attempt0.in", "r")
fo = open("output.txt", "w")
templines = fi.readlines()
T = int(templines[0])
for i in range(T):
    answer = run(templines[i+1])
    fo.write("Case #" + str(i+1) + ": " + answer + "\n")
fi.close()
fo.close()
