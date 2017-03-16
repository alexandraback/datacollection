__author__ = 'tegjyot'

import fileinput

def LASTROWS(matrix):
    dict={}
    list1=[]
    for row in matrix:
        for j in row:
            if j in dict:
                dict[j]+=1
            else:
                dict[j]=1
    for num in dict.keys():
        if dict[num]%2!=0:
            list1.append(num)

    list1.sort()
    return list1


if __name__ == "__main__":
    f = fileinput.input()
    T=int(f.readline())
    for case in range(1,T+1):
         N=int(f.readline())
         matrix=[]
         for rows in range(N*2-1):
             row=[int(i) for i in f.readline().strip().split()]
             matrix.append(row)
         last_rows=LASTROWS(matrix)
         print("Case #{0}: {1}".format(case, ' '.join([str(i) for i in last_rows])))