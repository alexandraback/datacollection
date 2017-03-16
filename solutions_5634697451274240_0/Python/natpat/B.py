def flips(s):
    if(s == ''): return 0

    i = 0
    while i < len(s) and s[-(i+1)] == '+':
        i+=1
    if(i > 0):
        return flips(s[:-i])

    swaps = 1
    charOn = s[0]
    for c in s:
        if c != charOn:
            charOn = c
            swaps+= 1

    return swaps
        

for i in range(int(raw_input())):
    case = i + 1
    s = raw_input()
    print "Case #" + str(case) + ": " + str(flips(s))
    
