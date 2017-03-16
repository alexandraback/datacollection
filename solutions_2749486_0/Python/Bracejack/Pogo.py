cases = int(raw_input())
case = 1

vowels = set('aeiou')

while case <= cases:
    
    x, y = [int(s) for s in raw_input().split()]
    ans = ''
    if x > 0:
        ans = ans + 'WE' * x
    else:
        ans = ans + 'EW' * abs(x)
    if y > 0:
        ans = ans + 'SN' * y
    else:
        ans = ans + 'NS' * abs(y)
    
    print "Case #" + str(case) + ': ' + ans
    case += 1