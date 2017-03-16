# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

#Problem 1
input_file = open(input("input from: "), "r")
output_file = open(input("output to: "), "w")
T = int(input_file.readline().strip())
for i in range(T):
    S = input_file.readline().strip().split()[1]
    c_sum = 0
    result = 0
    for d in range(len(S)):
        if S[d]!='0' and d>c_sum:
            result += d-c_sum
            c_sum = d
        c_sum += int(S[d])
    output_file.write("Case #"+str(i+1)+": "+str(result)+"\n")
input_file.close()
output_file.close()

# <codecell>

#Problem 2
input_file = open(input("input from: "), "r")
#output_file = open(input("output to: "), "w")
T = int(input_file.readline().strip())
for i in range(T):
    D = int(input_file.readline().strip())
    P = [int(i) for i in input_file.readline().strip().split()]
    P.append(0)
    P = sorted(P, reverse=True)
    C = [i for i in range(len(P))]
    minp = P[0]
    mini = -1
    while mini!=0:
        mini = 0
        for i in range(len(P)):
            p = max(int(ceil(P[0]/2)), P[i])+C[i]
            if p < minp:
                minp = p
                mini = i
        P = [int(ceil(P[i]/2)) if i<mini else P[i] for i in range(len(P))]
        C = [C[i]*2+C[mini] if i<mini else C[i]+2*C[mini] for i in range(len(C))]
        print(P,C)
    print(minp, mini)
    #output_file.write("Case #"+str(i+1)+": "+str(result)+"\n")
input_file.close()
#output_file.close()

# <codecell>

#Problem 3
import numpy as np

input_file = open(input("input from: "), "r")
output_file = open(input("output to: "), "w")
i = [[0,-1,0,0], [1,0,0,0], [0,0,0,-1], [0,0,1,0]]
j = [[0,0,0,-1], [0,0,-1,0], [0,1,0,0], [1,0,0,0]]
k = [[0,0,1,0], [0,0,0,-1], [-1,0,0,0], [0,1,0,0]]
neg_one = np.dot(i,i)
one = np.dot(neg_one, neg_one)
T = int(input_file.readline().strip())
for pupu in range(T):
    [L, X] = input_file.readline().strip().split()
    [L, X] = int(L), int(X)
    result = one
    c_set = set()
    for haha in range(L):
        c = input_file.read(1)
        c_set.add(c)
        result = np.dot(result, eval(c))
    input_file.readline()
    if np.all(result==one) or len(c_set)==1:
        result = 'NO'
    elif np.all(result==neg_one):
        result = 'YES' if X%2==1 else 'NO'
    elif np.all(np.dot(result,result)==one):
        result = 'YES' if X%2==0 and (X//2)%2==1 else 'NO'
    else:
        result = 'YES' if X%2==0 and (X//2)%2==1 else 'NO'
    output_file.write("Case #"+str(pupu+1)+": "+str(result)+"\n")
input_file.close()
output_file.close()

# <codecell>

#Problem 4
input_file = open(input("input from: "), "r")
output_file = open(input("output to: "), "w")
T = int(input_file.readline().strip())
for i in range(T):
    X,R,C = [int(j) for j in input_file.readline().strip().split()]
    if X>=7:
        result = 'RICHARD'
    elif X==1:
        result = 'GABRIEL'
    elif X==2:
        result = 'GABRIEL' if R%2==0 or C%2==0 else 'RICHARD'
    elif X==3:
        if R%3 and C%3:
            result = 'RICHARD'
        elif R==1 or C==1:
            result = 'RICHARD'
        else:
            result = 'GABRIEL'
    elif X==4:
        if R==1 or C==1:
            result = 'RICHARD'
        elif R<4 and C<4:
            result = 'RICHARD'
        elif R>=3 and C>=3: # these two cases only for small data set
            result = 'GABRIEL' 
        else:
            result = 'RICHARD'
    output_file.write("Case #"+str(i+1)+": "+str(result)+"\n")
input_file.close()
output_file.close()

# <codecell>

def test(s):
    result = one
    for haha in s:
        result = np.dot(result, eval(haha))
    if np.all(result==i):
        return 'i'
    elif np.all(result==np.negative(i)):
        return '-i'
    elif np.all(result==j):
        return 'j'
    elif np.all(result==np.negative(j)):
        return '-j'
    elif np.all(result==k):
        return 'k'
    elif np.all(result==np.negative(k)):
        return '-k'
    elif np.all(result==one):
        return '1'
    elif np.all(result==neg_one):
        return '-1'
    return result

# <codecell>

test('ik')

# <codecell>


