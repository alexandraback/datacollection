from multiprocessing import Pool
import itertools

def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret

#======================== BOF  =============================#

def valid(train):
    used = set()
    begin = 0
    end = 0
    while begin < len(train):
        if train[begin] in used:
            return False
        while end < len(train) and train[end] == train[begin]:
            end += 1
        used.add(train[begin])
        begin = end
    return True

def solver(data_container):
    n = data_container.n
    trains = data_container.trains

    ans = 0
    for perm in itertools.permutations(range(n)):
        train = ''
        for train_id in perm:
            train += trains[train_id]
        if valid(train):
            ans += 1

    return str(ans)


class DataContainer:
    def __init__(self):
        self.n = input()
        self.trains = read_array()
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
