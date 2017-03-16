import itertools

file=open('input.txt','rt')
out_file = open('output.txt','wt')

test_cases = int(file.readline())

def powerset(s):
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

def mym(nos):
    m = dict()

    for permute in powerset(nos):
        s = sum(permute)
        if s in m:
            print()
            print(' '.join([str(x) for x in permute]))
            print(' '.join([str(x) for x in m[s]]))
            return
        else:
            m[s] = permute

    print('Impossible')

for test_case in range(0, test_cases):
    tokens = file.readline().split(' ')
    tokens = [int(x) for x in tokens]
    num_nos = tokens.pop(0)
    nos = sorted(tokens)

    print('Case #{0}: '.format(test_case+1), end='')
    mym(nos)


out_file.flush()
out_file.close()