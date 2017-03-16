def solve(f):
    c, f, x = map(float, f.readline().split())

    output = 0.0

    prod = 2.0
    while True:
        eta = x/prod
        newEta = c/prod + x/(prod+f)
        if newEta < eta:
            output += c/prod
            prod += f
        else:
            output += eta
            break

    return output

