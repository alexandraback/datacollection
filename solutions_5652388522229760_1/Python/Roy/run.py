lines = open("A-large.in").readlines()

T = int(lines[0])

caseno = 1

for line in lines[1:T+1]:
    line = line.lstrip().rstrip()
    N = int(line)
    ans = N
    if N == 0:
        ans = "INSOMNIA"
    else:
        digitscount = 0
        digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        current = N
        while digitscount < 10:
            currentSTR = str(current)
            for c in currentSTR:
                cint = int(c)
                if digits[cint] == 0:
                    digits[cint] = 1
                    digitscount = digitscount + 1
            ans = current
            current = current + N
    print "Case #%s: %s" % (caseno, ans)
    caseno = caseno + 1