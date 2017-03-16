def readstr():
    return buf.pop()

def readstrs():
    return buf.pop().split()

def readint():
    return int(readstr())

def readints():
    return [int(e) for e in readstrs()]

def readparam():
    'read and display'
    ans = ''
    return '\n' + ans + '\n\n'

def opp(my_value, my_votes, C):
    my_score = my_value + my_votes
    return sum(max(0, my_score - opp_value) for opp_value in C)

def solve():
    'read and answer'
    C = [float(i) for i in readints()[1:]]
    S = 1.0 / sum(C)
    for i in range(len(C)):
        C[i] *= S
    ans = []
    for i in range(len(C)):
        my_value = C[i]
        my_min = 0.0
        my_max = 1.0
        while my_max - my_min >= 0.0000001:
            my_med = (my_max + my_min) / 2
            med_val = opp(my_value, my_med, C)
            #min_val = opp(my_value, my_min, C)
            #max_val = opp(my_value, my_max, C)
            if med_val <= 1:
                my_min = my_med
            elif med_val > 1:
                my_max = my_med
            else:
                raise BaseException('%f %f %f\n%f %f\n%s' % (
                  my_value, my_min, my_max,
                  min_val, max_val,
                  ' '.join(str(c) for c in C)))
        ans.append((my_max + my_min) / 2)
    return ' '.join(str(a * 100) for a in ans)

if __name__ == '__main__':
    from sys import stdin
    buf = []
    for line in stdin:
        buf.append(line)
    buf.reverse()
    N = int(buf.pop())

    for i in range(1, N+1):
        print 'Case #%d: %s' % (i, solve())
