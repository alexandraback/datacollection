input_file = 'A-small-attempt1.in'
output_file = 'output.txt'

f = open(input_file, 'r')
out = open(output_file, 'w')

v = ['a', 'e', 'i', 'o', 'u']

def solve(test, s, n):
    c = 0
    le = len(s)
    vowp = []
    m = [[0 for x in range(le)] for x in range(le)] 
    for i in range(le):
        if s[i] in v:
            vowp.append(i) 
    if len(vowp) == 0:
        for let in range(le - n + 1):
            c += le - let - n + 1
        out.write("Case #" + str(test) + ": " + str(c) + "\n")
        return

    vowp.append(le)
    start = 0
    groups = []
    for i in vowp:
        stop = i
        if stop - start < n:
            start = stop + 1
        else:
            for let in range(stop - start - n + 1):
                groups.append([start + let, start + let + n - 1])
            start = stop + 1
    for it in groups:
        a = it[0]
        b = it[1]
        for i in range(0, a + 1):
            for j in range(b, le):
                if m[i][j] == 0:
                    c+=1
                    m[i][j] = 1
    out.write("Case #" + str(test) + ": " + str(c) + "\n")
        

#read no test cases:
no_tests = int(f.readline())

for test in range(0, no_tests):
    line = f.readline()
    l = line.split()
    s = l[0]
    n = int(l[1])
    print s
    print n
    solve(test+1, s, n)
    
f.close()
out.close()
