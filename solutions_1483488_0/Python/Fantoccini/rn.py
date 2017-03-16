'''
Created on Apr 14, 2012

@author: Fantoccini
'''

fin = open("r.in", "r")
fout = open("r.out", "w")
t = int (fin.readline())
for i in range(t):
    line = fin.readline()
    line = line.strip()
    nums = line.split()
    a = int(nums[0])
    b = int(nums[1])
    c = 0
    for j in range(a, b + 1):
        sj = str(j) + str(j)
        st = set()
        for k in range(1, len(sj) / 2, 1):
            sk = sj[k:k + len(sj) / 2]
            if int(sk) > j and int(sk) <= b and sk not in st:
                st.add(sk)
                c += 1
    fout.write("Case #" + str (i + 1) + ": " + str(c) + "\n")
fin.close()
fout.close()
