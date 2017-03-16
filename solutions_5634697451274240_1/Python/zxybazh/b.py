def flip(s):
    t = ""
    for w in s:
        if w == '+': t += '-'
        else: t += '+'
    return t

def calc(s):
    while not (s.startswith('+') or s.startswith('-')): s = s[1:]
    while not (s.endswith('+') or s.endswith('-')): s = s[:-1]
    ans = 0
    tip = len(s)
    while (True):
        while tip > 0 and s[tip - 1] == '+': tip -= 1
        if (tip == 0): return ans
        if s.startswith('-'):
            ans += 1
            s = flip(s[:tip][::-1]) + s[tip:]
            # print s
        else:
            ans += 2
            s = s.find('-') * '-' + s[s.find('-'):]
            # print s
            s = flip(s[:tip][::-1]) + s[tip:]
            # print s

file = open("B-large.in", "r")
a = file.readlines()
T = int(a[0])
for i in xrange(1, len(a)):
    print "Case #%d: %d" % (i, calc(a[i]))
