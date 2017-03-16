from math import sqrt
raw_input()
n, j = map(int, raw_input().split(' '))
found = 0
print "Case #1:"
for i in range(2 ** (n-2)):
    numstr = '1' + ("{0:0"+str(n-2)+"b}").format(i) + '1'
    divs = []
    for b in range(2,11):
        num = int(numstr, b)
        for div in range(2, int(sqrt(num))):
            if num % div == 0:
                divs.append(div)
                break
        if len(divs) < b - 1:
            break
    if len(divs) == 9:
        print numstr, " ".join(map(str, divs))
        found += 1
        if found == j:
            break
