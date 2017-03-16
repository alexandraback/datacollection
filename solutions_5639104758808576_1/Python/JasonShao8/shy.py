t = input()
for poo in range(t):
    n, s = raw_input().split()
    seen = int(s[0])
    need = 0
    for i in range(1, int(n)+1):
        if int(s[i]) != 0 and i > seen + need:
            need = i - seen
        seen += int(s[i])

    print "Case #" + str(poo + 1) + ":", need
