import numpy

def read_problem(f):
    itr = iter(f)

    T = int(itr.next())

    for _ in xrange(T):
        (N, M) = map(int, itr.next().strip().split())

        arr = numpy.zeros((N, M), numpy.uint)

        for i in xrange(N):
            arr[i, :] = map(int, itr.next().strip().split())

        yield arr


def yesno(v):
    if v:
        return 'YES'
    else:
        return 'NO'


def can_mow(lawn):
    mylawn = numpy.ones(lawn.shape, numpy.uint)*100

    for i in xrange(lawn.shape[0]):
        mylawn[i, :] = mylawn[i, :].clip(max=lawn[i, :].max())

    for i in xrange(lawn.shape[1]):
        mylawn[:, i] = mylawn[:, i].clip(max=lawn[:, i].max())

    return (lawn == mylawn).all()


def main():
    import sys
    with open(sys.argv[1], 'rt') as f:
        for case, lawn in enumerate(read_problem(f)):
            print 'Case #%d: %s' % (case+1, yesno(can_mow(lawn)))

if __name__ == '__main__':
    main()
