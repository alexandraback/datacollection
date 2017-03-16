#!/usr/bin/python
# vi: set fileencoding=utf-8 :

'''
Google code jam 2016 round 1 B
'''

def remove_digit(D, S):
    for d in D:
        for i in range(len(S)):
            if S[i] == d:
                S = S[:i] + S[i+1:]
                break
    return S


def answer(S):
    ans = []
    occur = [0 for i in range(10)]
    while 'Z' in S:
        ans.append('0')
        S = remove_digit('ZERO', S)
    while 'W' in S:
        ans.append('2')
        S = remove_digit('TWO', S)
    while 'X' in S:
        ans.append('6')
        S = remove_digit('SIX', S)
    while 'G' in S:
        ans.append('8')
        S = remove_digit('EIGHT', S)
    while 'S' in S:
        ans.append('7')
        S = remove_digit('SEVEN', S)
    while 'V' in S:
        ans.append('5')
        S = remove_digit('FIVE', S)
    while 'F' in S:
        ans.append('4')
        S = remove_digit('FOUR', S)
    while 'T' in S:
        ans.append('3')
        S = remove_digit('THREE', S)
    while 'O' in S:
        ans.append('1')
        S = remove_digit('ONE', S)
    while 'N' in S:
        ans.append('9')
        S = remove_digit('NINE', S)
    ans.sort()
    return ''.join(ans)


T = int(raw_input())
for case_number in range(1, T + 1):
    S = raw_input().rstrip()
    print 'Case #%d: %s' % (case_number, answer(S))
