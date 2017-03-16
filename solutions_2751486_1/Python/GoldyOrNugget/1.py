f = open('in.txt')
num = int(f.readline())

cons = 'bcdfghjklmnpqrstvwxyz'


def solve(name, n):
    is_s = [False] * len(name)
    is_e =[False] * len(name)
    #s_ends_at = [None] * len(name)
    counts = [0] * len(name)
    to_look_at = [None] * len(name)

    for i in xrange(len(name)):
        if name[i] in cons:
            counts[i] = counts[i-1] + 1
            if counts[i] >= n:
                is_e[i] = True
                #s_ends_at[i] = i - n + 1
                is_s[i-n+1] = True


    last_end = None
    for i in xrange(len(name)-n, -1, -1):
        # print name[i]
        if last_end != None:
            to_look_at[i] = last_end

        # assert i+n-1 < len(name)
        if is_e[i+n-1]:
            last_end = i+n-1
            # print 'setting', i

    # print is_s
    # print is_e
    soln = 0
    for i in xrange(len(name)):
        # print 'at ', name[i],
        if is_s[i]:
            soln += len(name) - i - n + 1
            # print 'adding', len(name) - i - n + 1
        elif to_look_at[i] != None:
            soln += len(name) - to_look_at[i]
            # print 'saddig', len(name) - to_look_at[i]



    return soln




solve('straight', 3)
solve('tsetse', 2)

for case in xrange(num):
  name, n = f.readline().split()
  n = int(n)
  print 'Case #%d: %d' % (case+1, solve(name, n))

