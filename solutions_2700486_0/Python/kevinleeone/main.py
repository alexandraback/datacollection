import sys, math, operator, functools

def c(n, k):
    return functools.reduce(operator.mul, range(n - k + 1, n + 1)) / functools.reduce(operator.mul, range(1, k + 1))

def numberToLayer(layer):
   return int(2 * (layer ** 2) - layer)

if __name__ == '__main__':
    cases = int(sys.stdin.readline())
    for i in range(1, cases + 1):
        prob = 0.0
        (number, x, y) = map(int, sys.stdin.readline().split())
        layer = int((abs(x) + abs(y)) / 2 + 1)
        height = int(abs(y))
        if number <= numberToLayer(layer - 1):
            prob = 0.0
        elif numberToLayer(layer) <= number:
            prob = 1.0
        else:
            delta = number - numberToLayer(layer - 1)
            if delta <= height or int(height / 2) + 1 == layer:
                prob = 0.0
            elif height < delta - (2 * layer - 2):
                prob = 1.0
            else:
                for j in range(height + 1, delta + 1):
                    prob = prob + 0.5 ** delta * c(delta, j)
        print('Case #%d: %f' % (i, prob))
