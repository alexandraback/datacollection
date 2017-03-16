from multiprocessing import Pool

def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret

#======================== BOF  =============================#

def gcd(a, b):
    if a == 0:
        return b
    elif a > b:
        return gcd(b, a)
    else:
        return gcd(b%a, a)

def all2(q):
    while q % 2 == 0:
        q /= 2
    return q == 1


def solver(data_container):
    p, q = data_container.p, data_container.q
    _gcd = gcd(p, q)
    p, q = p / _gcd, q / _gcd

    if not all2(q):
        return 'impossible'

    twos = 0
    while p * 2 < q:
        twos += 1
        q /= 2
    return str(twos + 1)


class DataContainer:
    def __init__(self):
        self.p, self.q = map(int, raw_input().split('/'))
        pass # read data

#======================== EOF  =============================#


if __name__ == '__main__':
    NUM_THREAD = 2
    USE_MULTI = False

    T = input()
    input_queue = [DataContainer() for _ in xrange(T)]
    
    if USE_MULTI:
        pool = Pool(NUM_THREAD)
        result = pool.map(solver, input_queue)
    else:
        result = []
        for i in xrange(T):
            result.append(solver(input_queue[i]))

    for i in range(T):
        print 'Case #%d: %s' % (i+1, result[i])
