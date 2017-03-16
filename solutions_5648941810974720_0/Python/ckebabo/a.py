numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

found = False
ans = ''

def foo(chars, number, s):
    global found, ans

    if sum(chars) == 0:
        ans = s
        found = True
        return

    if number==10:
        return

    k = 2000
    l = chars[:]

    for c in numbers[number]:
        k = min(k, chars[ord(c)])

    for n in xrange(k,-1,-1):
        for c in numbers[number]:
            l[ord(c)] -= n

        ss = s
        if n>0: ss += str(number)*n
        foo(l, number+1, ss)
        if found: return

        l = chars[:]

for cs in xrange(int(raw_input())):
    s = raw_input()
    chars = [0]*256

    for ch in s:
        chars[ord(ch)] += 1
    
    found = False
    ans = ''
    foo(chars, 0, '')
    print 'Case #%d:'%(cs+1), ans
