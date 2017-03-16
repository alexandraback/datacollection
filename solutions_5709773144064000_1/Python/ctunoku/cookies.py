inf = 100000

def time(c, f, x):
    best = inf

    rate = 2
    time = 0
    while True:
        cur = time + x / rate
        if cur > best:
            return best
        best = cur

        time += c / rate
        rate += f

result = ''
with open('input.txt') as f:
    cases = int(f.readline()[:-1])

    for case in range(cases):
        case += 1

        line = f.readline()[:-1]
        c, F, x = line.split()
        c, F, x = float(c), float(F), float(x)

        result += "Case #%s: %.7f\n" % (case, time(c, F, x))
with open('output.txt', 'w') as f:
    f.write(result)