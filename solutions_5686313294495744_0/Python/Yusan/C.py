#!/usr/bin/python
# vi: set fileencoding=utf-8 :

'''
Google code jam 2016 round 1 B
'''

def is_fake(x, topic):
    original0 = {}
    original1 = {}
    for i in range(len(x)):
        if x[i] == 0:
            original0[topic[i][0]] = True
            original1[topic[i][1]] = True
    for i in range(len(x)):
        if x[i] == 1:
            if topic[i][0] not in original0:
                return False
            if topic[i][1] not in original1:
                return False
    else:
        return True


def answer(N, topic):
    stack = [[]]
    max_fake = 0
    while len(stack) > 0:
        x = stack.pop()
        if len(x) == N:
            if is_fake(x, topic) == True:
                if max_fake < sum(x):
                    max_fake = sum(x)
        else:
            stack.append(x + [0])
            stack.append(x + [1])
    return max_fake


T = int(raw_input())
for case_number in range(1, T + 1):
    N = int(raw_input())
    topic = []
    for i in range(N):
        topic.append(raw_input().rstrip().split())
    print 'Case #%d: %s' % (case_number, answer(N, topic))
