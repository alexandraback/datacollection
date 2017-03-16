# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

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


