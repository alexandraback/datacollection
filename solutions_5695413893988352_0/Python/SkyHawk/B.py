import sys
import copy

def get_flag(old_flag, left, right):
    if old_flag != 0:
        return old_flag
    if left == right:
        return 0
    return 1 if left > right else -1

def solve(s1_param, s2_param):
    s1 = copy.deepcopy(s1_param)
    s2 = copy.deepcopy(s2_param)
    # print >> sys.stderr, '################# ' + ''.join(s1) + " " + ''.join(s2)
    flag = 0
    for i in range(len(s1)):
        if s1[i] != '?' and s2[i] != '?':
            flag = get_flag(flag, s1[i], s2[i])
            continue
        if flag > 0:
            if s1[i] == '?':
                s1[i] = '0'
            if s2[i] == '?':
                s2[i] = '9'
            continue
        if flag < 0:
            if s1[i] == '?':
                s1[i] = '9'
            if s2[i] == '?':
                s2[i] = '0'
            continue
        if flag == 0:
            # print >> sys.stderr, '### ' + ''.join(s1) + " " + ''.join(s2)
            if i + 1 == len(s1):# or (s1[i+1] == '?' and s2[i+1] == '?'):
                if s1[i] == '?' and s2[i] == '?':
                    s1[i] = '0'
                    s2[i] = '0'
                    continue
                if s1[i] == '?':
                    s1[i] = s2[i]
                else:
                    s2[i] = s1[i]
                continue
            if i + 1 < len(s1):
                # print i, s1, s2
                if s1[i] == '?' and s2[i] == '?':
                    [ans11, ans12] = solve(s1[:i] + ['0'] + s1[i+1:], s2[:i] + ['0'] + s2[i+1:])
                    [ans21, ans22] = solve(s1[:i] + ['1'] + s1[i+1:], s2[:i] + ['0'] + s2[i+1:])
                    [ans31, ans32] = solve(s1[:i] + ['0'] + s1[i+1:], s2[:i] + ['1'] + s2[i+1:])
                    d1 = abs(int(''.join(ans11)) - int(''.join(ans12)))
                    d2 = abs(int(''.join(ans21)) - int(''.join(ans22)))
                    d3 = abs(int(''.join(ans31)) - int(''.join(ans32)))
                    if d1 == min(d1,d2,d3):
                        return (ans11, ans12)
                    if d2 == min(d1,d2,d3):
                        return (ans21, ans22)
                    if d3 == min(d1,d2,d3):
                        return (ans31, ans32)
                    continue
                if s1[i] == '?':
                    if int(s2[i]) > 0:
                        [ans11, ans12] = solve(s1[:i] + [str(int(s2[i]) - 1)] + s1[i+1:], s2)
                        d1 = abs(int(''.join(ans11)) - int(''.join(ans12)))
                    else:
                        d1 = 10000000000000000000
                    [ans21, ans22] = solve(s1[:i] + [s2[i]] + s1[i+1:], s2)
                    if int(s2[i]) < 9:
                        [ans31, ans32] = solve(s1[:i] + [str(int(s2[i]) + 1)] + s1[i+1:], s2)
                        d3 = abs(int(''.join(ans31)) - int(''.join(ans32)))
                    else:
                        d3 = 10000000000000000000
                    d2 = abs(int(''.join(ans21)) - int(''.join(ans22)))
                    if d1 == min(d1,d2,d3):
                        return (ans11, ans12)
                    if d2 == min(d1,d2,d3):
                        return (ans21, ans22)
                    if d3 == min(d1,d2,d3):
                        return (ans31, ans32)
                    continue
                if s2[i] == '?':
                    if int(s1[i]) > 0:
                        [ans11, ans12] = solve(s1, s2[:i] + [str(int(s1[i]) - 1)] + s2[i+1:])
                        d1 = abs(int(''.join(ans11)) - int(''.join(ans12)))
                    else:
                        d1 = 10000000000000000000
                    [ans21, ans22] = solve(s1, s2[:i] + [s1[i]] + s2[i+1:])
                    if int(s1[i]) < 9:
                        [ans31, ans32] = solve(s1, s2[:i] + [str(int(s1[i]) + 1)] + s2[i+1:])
                        d3 = abs(int(''.join(ans31)) - int(''.join(ans32)))
                    else:
                        d3 = 10000000000000000000
                    d2 = abs(int(''.join(ans21)) - int(''.join(ans22)))
                    if d1 == min(d1,d2,d3):
                        return (ans11, ans12)
                    if d2 == min(d1,d2,d3):
                        return (ans21, ans22)
                    if d3 == min(d1,d2,d3):
                        return (ans31, ans32)
    return s1, s2


T = int(raw_input())
for case_idx in xrange(1, T+1):
    sys.stdout.write("Case #{}: ".format(case_idx))
    [s1,s2] = raw_input().strip().split()
    s1, s2 = solve(list(s1), list(s2))
    print ''.join(s1), ''.join(s2)


