#!/usr/bin/python

import sys

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

class Bunch:
    def __init__( self, **kwds ):
        self.__dict__ = kwds


pause_after_trace = False
def mtrace(*strs):
    # return
    atrace(*strs)

def atrace(*strs):
    f = sys.stderr
    print >> f, '..',
    for str in strs:
        print >> f, str,
    print >> f
    if pause_after_trace:
        response = raw_input('? ')
        if response == 'q':
            sys.exit(1)

def memoize(f):
    memos = {}
    def memoized_f( *args ):
        try:
            result = memos[args]
            mtrace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            mtrace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

# ------------------------------------------------------------------------------

def solve_1(cq, jq):
    C_IS_LOWER = 1
    J_IS_LOWER = 2
    DONT_KNOW_MIGHT_BE_EQUAL = 3

    c = ''; j = ''

    state = DONT_KNOW_MIGHT_BE_EQUAL
    for (c_dq, j_dq) in zip(cq,jq):
        # mtrace(c_dq, j_dq)
        if c_dq == '?' and j_dq == '?':
            if state == DONT_KNOW_MIGHT_BE_EQUAL:
                # Make them the same, to continue the possibility that they're equal,
                # and make them both 0 for the tie-breaking rules.
                c_d = '0'; j_d = '0'
                # state stays the same

            elif state == C_IS_LOWER:
                # i.e., somewhere left of this digit,
                # C must have had a lower digit than J
                # So now we want C to be as high as possible and J to be as low as possible.
                # But what about the tie-breaking rules?
                c_d = '9'; j_d = '0'
            elif state == J_IS_LOWER:
                c_d = '0'; j_d = '9'
            else:
                assert 0

        elif c_dq == '?':
            j_d = j_dq
            if state == DONT_KNOW_MIGHT_BE_EQUAL:
                # Make them the same
                c_d = j_d
            elif state == C_IS_LOWER:
                c_d = '9'
            elif state == J_IS_LOWER:
                c_d = '0'
            else:
                assert 0

        elif j_dq == '?':
            c_d = c_dq
            if state == DONT_KNOW_MIGHT_BE_EQUAL:
                # Make them the same
                j_d = c_d
            elif state == C_IS_LOWER:
                j_d = '0'
            elif state == J_IS_LOWER:
                j_d = '9'
            else:
                assert 0

        else:
            c_d = c_dq; j_d = j_dq
            if state == DONT_KNOW_MIGHT_BE_EQUAL:
                if c_d < j_d:
                    state = C_IS_LOWER
                elif j_d < c_d:
                    state = J_IS_LOWER
                elif c_d == j_d:
                    state = DONT_KNOW_MIGHT_BE_EQUAL
                else:
                    assert 0
            else:
                # Can't change the state now.
                pass

        c += c_d; j += j_d

    return (c,j)

digits = list('0123456789')

def generate_possibles(q):

    results = []
    
    ar = [''] * len(q)

    def something(i):
        if i < len(q):
            dq = q[i]
            if dq == '?':
                for d in digits:
                    ar[i] = d
                    something(i+1)
            else:
                ar[i] = dq
                something(i+1)
        else:
            results.append(int(''.join(ar)))

    something(0)

    return results

#def solve_2(cq, jq):
#    fi = None
#    for i,(cdq,jdq) in enumerate(zip(cq,jq)):
#        if cdq == '?' or jdq == '?':
#            pass
#        elif cdq == jdq:
#            pass
#        else:
#            # this is the leftmost char that forces a difference.
#            fi = i
#            break
#
#    if fi is None:
#        # The two scores can be equal.
#        # So just choose digits to minimize scores.
#        for (cdq,jdq) in zip(cq,jq):
#            if cdq == '?' and jdq == '?':
#                cd = '0'; jd = '0'
#            elif cdq == '?':
#                cd = jdq; jd = jdq
#            elif jdq == '?':
#                cd = cdq; jd = cdq
#            else:
#                assert cdq == jdq
#                cd = cdq; jd = jdq
#            c += cd; j += jd
#
#        return (c,j)
#
#    else:
#        # The two scores can't be equal
#
#        if cq[fi] < jq[fi]:
#            fi_fact = 'c<j'
#        elif cq[fi] > jq[fi]:
#            fi_fact = 'c>j'
#        else:
#            assert 0
#
#        for assumption in ['c<j', 'c>j']:
#
#            c == ''; j = ''
#
#            for i,(cdq,jdq) in enumerate(zip(cq,jq)):
#
#                if i < fi-1:
#                    # make them the same.
#                    if cdq == '?' and jdq == '?':
#                        cd = '0'; jd = '0'
#                    elif cdq == '?':
#                        cd = jdq; jd = jdq
#                    elif jdq == '?':
#                        cd = cdq; jd = cdq
#                    else:
#                        assert cdq == jdq
#                        cd = cdq; jd = jdq
#
#                elif i == fi-1:
#                    if assumption == fi_fact:
#                        # make them the same
#                        if cdq == '?' and jdq == '?':
#                            cd = '0'; jd = '0'
#                        elif cdq == '?':
#                            cd = jdq; jd = jdq
#                        elif jdq == '?':
#                            cd = cdq; jd = cdq
#                        else:
#                            assert cdq == jdq
#                            cd = cdq; jd = jdq
#                    else:
#                        # make the digits in this position differ by 1, where possible
#                        if cdq == '?' and jdq == '?':
#                            if assumption == 'c<j' and fi_fact == 'c>j':
#                                cd = '0'; jd = '1'
#                            elif assumption == 'c>j' and fi_fact == 'c<j':
#                                cd = '1'; jd = '0'
#                            else:
#                                assert 0
#                        elif cdq == '?':
#                            jd = jdq
#                            if assumption == 'c<j' and fi_fact == 'c>j':
#                                cd = jdq-1
#                            elif assumption == 'c>j' and fi_fact == 'c<j':
#                                if  ???????
#                                cd = jdq+1
#                            else:
#                                assert 0
#                        elif jdq == '?':
#                            cd = cdq; jd = cdq
#                        else:
#                            assert cdq == jdq
#                            cd = cdq; jd = jdq
#
#                elif i == fi:
#                    assert cdq != '?'
#                    assert jdq != '?'
#                    cd = cdq
#                    jd = jdq
#
#                elif i > fi:
#                    if assumption == 'c<j':
#                        cd = '9' if cdq == '?' else cdq
#                        jd = '0' if jdq == '?' else jdq
#                    elif assumption == 'c>j':
#                        cd = '0' if cdq == '?' else cdq
#                        jd = '9' if jdq == '?' else jdq
#                    else:
#                        assert 0
#
#                else:
#                    assert 0
#
#                c += cd; j += jd



    

n_cases = int(getline())
mtrace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    mtrace()
    atrace( 'Case #', case_num )

    (cq,jq) = getline().split()
    mtrace(cq, jq)

    assert len(cq) == len(jq)

    # (c1,j1) = solve_1(cq,jq)
    # diff1 = abs(int(c1) - int(j1))
    # mtrace('soln1:', c1,j1, diff1)

    # (c2,j2) = solve_2(cq,jq)

    min_diff_so_far = None
    cds = generate_possibles(cq)
    jds = generate_possibles(jq)
    for cd in cds:
        for jd in jds:
            diff = abs(cd - jd)
            if (
                min_diff_so_far is None
                or 
                diff < min_diff_so_far
                or
                diff == min_diff_so_far and cd < min_cd
                or
                diff == min_diff_so_far and cd == min_cd and jd < min_jd
            ):
                min_diff_so_far = diff
                min_cd = cd
                min_jd = jd

    k = len(cq)
    min_cd = str(min_cd).zfill(k)
    min_jd = str(min_jd).zfill(k)

    print 'Case #%d: %s %s' % (case_num, min_cd, min_jd)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
