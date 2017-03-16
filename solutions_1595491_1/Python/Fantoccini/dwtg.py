'''
Created on Apr 14, 2012

@author: Fantoccini
'''
m = [[0 for col in range(31)] for row in range(11)]

for i in range (11):
    for j in range(i, i + 3):
        if j > 10 :
            continue
        for k in range(j, j + 3):
            if k > 10:
                continue
            if k - i > 2:
                continue
            s = i + j + k
            if k - i > 1 and m[k][s] == 0:
                m[k][s] = 2
            else:
                m[k][s] = 1
                
for i in range(11):
    for j in range(30, -1, -1):
        if m[i][j] > 0:
            break;
        m[i][j] = 1

for i in range(11):
    print m[i]

fin = open("d.in", "r")
fout = open("d.out", "w")
t = int (fin.readline())
for i in range(t):
    line = fin.readline()
    line = line.strip()
    nums = line.split()
    c = 0
    n = int (nums[0])
    s = int (nums[1])
    p = int (nums[2])
    for j in range(3, len(nums)):
        if m[p][int(nums[j])] == 1:
            c += 1
        if m[p][int(nums[j])] == 2 and s > 0:
            c += 1
            s -= 1
    fout.write("Case #" + str (i + 1) + ": " + str(c) + "\n")


fin.close()
fout.close()
