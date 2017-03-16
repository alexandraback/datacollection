product = lambda l: reduce(lambda x,y: x*y, l,1)
def correctness_by_index(probabilities_of_success):
    return [product(probabilities_of_success[:1+i]) for i in \
            range(len(probabilities_of_success))]

def expected_finish(typed, length, p_success):
    chance_of_success = product(p_success)
    chance_of_failure = 1-chance_of_success
    e_succ =(1+length - typed)
    e_fail = (1+length) + e_succ
    return  e_succ*chance_of_success + e_fail*chance_of_failure

def expected_retype(typed, length, p_success):
    return 2+length

def expected_backspace(typed, length, p_success, i):
    assert i <= typed
    new_start = typed - i
    return i+expected_finish(new_start, length, p_success[:new_start])

def pmin(iterable):
    return min(iterable)
def minimize_keystrokes(typed, length, p_success):
    return pmin(
                [expected_finish(typed, length, p_success),\
                expected_retype(typed, length, p_success)]+\
                [expected_backspace(typed, length, p_success, i+1) for i in\
                    range(typed)])

def run(file):
    lines = file.xreadlines()
    next(lines) # ignore first
    case = 1
    while True:
        try:
            typed, length = [int(i) for i in next(lines).split()]
            p_success = [float(f) for f in next(lines).split()]
            print "Case #{}: {:6f}".format(case, minimize_keystrokes(typed, length, p_success))
            case += 1
        except StopIteration:
            break

if __name__ == '__main__':
    import sys
    run(open(sys.argv[1]))
