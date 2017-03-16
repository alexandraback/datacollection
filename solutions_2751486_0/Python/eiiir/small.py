filename = "A-small-attempt0.in" # change later
f = open(filename)
T = int(f.readline())
vowels = "aiueo"
for case in range(1,T+1):
    s = f.readline()
    s = s.split()
    string = s[0]
    n = int(s[1])
    L = len(string)
    bin = []
    for ch in string:
        if ch in vowels:
            bin.append(0)
        else:
            bin.append(1)
    
    pattern = 0
    for k in range(L-1, -1, -1):
        counter = 0
        for j in range(k, L):
            if bin[j] == 1:
                counter  = counter + 1
            elif counter < n:
                counter = 0
            if counter >= n:
                pattern = pattern + 1
    print "Case #" + str(case) + ": " + str(pattern)