from itertools import product

T = int(input())

for i in range(T):
    string = raw_input().split()
    str1 = string[0]
    str2 = string[1]
    possible1 = []
    possible2 = []
    for j in range(len(str1)):
        possible1.append([])
        if(str1[j]=='?'):
            for k in range(10):
                possible1[j].append(str(k))
        else:
            possible1[j].append(str1[j])

        possible2.append([])
        if(str2[j]=='?'):
            for k in range(10):
                possible2[j].append(str(k))
        else:
            possible2[j].append(str2[j])
    list1 = []
    list2 = []
    diff = 999999999999999999
    temp1 = temp2 = 0
    for a in product(*possible1):
        list1.append(int(''.join(list(a))))
    for a in product(*possible2):
        list2.append(int(''.join(list(a))))
    list1.sort()
    list2.sort()
    x=y=0
    while(x<len(list1) and y<len(list2)):
        if abs(list1[x]-list2[y])<diff:
            diff=abs(list1[x]-list2[y])
            temp1 = list1[x]
            temp2 = list2[y]
        if list1[x] < list2[y]:
            x += 1
        else:
            y += 1
    print("Case #"+str(i+1)+": "+str(temp1).zfill(len(str1))+' '+str(temp2).zfill(len(str2)))
