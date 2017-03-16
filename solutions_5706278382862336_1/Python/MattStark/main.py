def solve(num, denom):
    if (tot * num) % denom != 0:
        return "impossible"
    amount = tot * num // denom
    return 41 - (len(bin(amount)) - 2) # msb only

f = open('tests/large.in', 'rU').readlines()[1:]
if not f[-1]:
    f = f[:-1]

tot = 1<<40
for i in range(0, len(f)):
    num, denom = map(int, f[i].split('/'))
    print("Case #%d: %s" % (i+1, solve(num, denom)))
