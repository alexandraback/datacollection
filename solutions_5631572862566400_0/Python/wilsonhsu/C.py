

def find_circle(bffs, i):
    circle = []
    students = set()
    while i not in students:
        students.add(i)
        circle.append(i)
        i = bffs[i]
    if i==circle[0] or i==circle[-2]:
        return circle
    else:
        return []

def find_sinks(bffs):
    sinks = set()
    for i in bffs:
        if i == 0:
            continue
        if i == bffs[bffs[i]]:
            sinks.add(i)
    return sinks

def solve(bffs):
    N = len(bffs)
    bffs = [0] + bffs
    sinks = find_sinks(bffs)
    sink_count = dict.fromkeys(sinks, 0)
    curmax = 0
    for i in range(1, N+1):
        if i in sinks:
            continue

        students = set()
        k = i
        while k not in students:
            students.add(k)
            k = bffs[k]

        if k in sinks:
            sink_count[k] = max(sink_count[k], len(students)-2)

        if k == i or k in sinks:
            curmax = max(curmax, len(students))

    sink_total = 0
    for k in sink_count:
        sink_total += sink_count[k]+sink_count[bffs[k]]+2
    sink_total //= 2

    return max(curmax, sink_total)

def run(name):
    f = open('{0}.in'.format(name), 'r')
    g = open('{0}.out'.format(name), 'w')

    T = int(f.readline())
    for t in range(T):
        N = int(f.readline())
        bffs = [int(i) for i in f.readline().split()]
        result = solve(bffs)
        g.write("Case #{0}: {1}\n".format(t+1, result))

    f.close()
    g.close()


if __name__ == '__main__':
    run('C-small-attempt1')
