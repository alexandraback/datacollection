import sys

def run(func):
    with open(sys.argv[1]) as handle:
        count = int(handle.readline())
        for x in range(count):
            yield func(handle)

def output(data):
    return '\n'.join('Case #{}: {}'.format(*pair) for pair in enumerate(data, start=1))

def test(func):
    print output(run(func))

def func(handle):
    name, n = handle.readline().strip().split()
    n = int(n)

    L = len(name)

    i = last = total = 0
    count = 0

    while i < L:
        if name[i] not in 'aeiou':
            count += 1
        else:
            count = 0
        if count >= n:
            before = i - n + 2 - last
            after = L - i
            total += after * before
            last = i - n + 2
        i += 1
    return total

test(func)

