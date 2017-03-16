fin = open('B-small-attempt0.in.txt','r')
#fin = open('A-large-practice.in.txt', 'r')
#fin = open('input.txt')

fout = open('output.txt', 'w')

numCases = int(fin.readline())

for cases in range(numCases):
    lst = list(map(int,fin.readline().split()))
    A = lst[0]
    B = lst[1]
    K = lst[2]

    sum = 0
    for i in range(A):
        for j in range(B):
            z = i & j
            if z<K:
                sum = sum +1
    #print(sum)
    fout.write("Case #" + str(cases+1) + ": "+str(sum)+'\n')

fin.close()
fout.close()