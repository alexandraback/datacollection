import functools
import itertools
import sys

def is_dijkstra(ss, x):
    """
    is_dijkstra(ss: str) -> bool
    """
    n = min(x, x % 4 + 8) # Room for improvement
    # print(ss, n)
    # print(list(itertools.chain(*itertools.repeat(list(map(c_to_cpair, ss)), n))))

    if n == 0:  
        out = False
    if len(set(ss)) <= 1:
        out = False

    acc = (1, 0)
    gen = itertools.chain(*itertools.repeat(list(map(c_to_cpair, ss)), n))

    for i, pair in enumerate(gen):
        acc = cpair_mul(acc, pair)
        # print(acc)
        if acc == c_to_cpair('i'):
            acc = (1, 0)
            # print(i)
            break

    for j, pair in enumerate(gen, i+1):
        acc = cpair_mul(acc, pair)
        # print(acc)        
        if acc == c_to_cpair('j'):
            # print(j)
            break

    out = functools.reduce(cpair_mul, gen, (1, 0)) == c_to_cpair('k')
    return tf_to_YESNO(out)


def cpair_reduce(ts):
    return functools.reduce(cpair_mul, ts, (1, 0))

def cpair_pow(a, n):
    q = n % 4
    if   q == 0:
        out = (1, 0)
    elif q == 1:
        out = a
    elif q == 2:
        out = (-1, 0)
    else:
        (x, y) = a
        out = (-x, -y)
    return out

def cpair_mul(a, b):
    (x, y) = a
    (p, q) = b
    pc = p.conjugate()
    qc = q.conjugate()
    return (x*p - y*qc, x*q + y*pc)

def c_to_cpair(c):
    d = {'i': (1j, 0), 'j': (0, 1), 'k': (0, 1j)}
    return d[c]

def tf_to_YESNO(tf):
    return "YES" if tf else "NO"

def parse(ss):
    n, rest = int(ss[0]), ss[1:]
    out = []
    for i in range(n):
        fst, snd = rest[2*i], rest[2*i + 1]
        l, m = map(int, fst.split())
        ss = snd.rstrip()
        out.append((ss, m))
    return out


if __name__ == '__main__':
    with open(sys.argv[1], "r") as f:
        data = parse([line for line in f if line.rstrip()])

    yesnos = (is_dijkstra(ss, m) for (ss, m) in data)
    for (i, yn) in enumerate(yesnos):
        print("Case #%d: %s" % (i + 1, yn))

