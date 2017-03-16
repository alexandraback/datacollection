#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 KuoE0 <kuoe0.tw@gmail.com>
#
# Distributed under terms of the MIT license.

"""

"""

import re

cnt = 0
set_list = None
visited = None

def zip_str(s):
    return re.sub(r'([a-z])\1+', r'\1', s)

def isValid(s):

    while s:
        head = s[0]
        tail = s[1:]

        if head in tail:
            return False

        s = tail

    return True




def DFS(cur_str):
    global cnt
    global visited
    global set_list

    if all(visited):
        cnt += 1
        return

    banned_char = set(cur_str)
    tail_char = None

    if cur_str:
        banned_char.remove(cur_str[-1])
        tail_char = cur_str[-1]

    for now in xrange(N):
        if not visited[now] and all([c not in banned_char for c in set(set_list[now])]):

            if not tail_char:
                visited[now] = True
                DFS(cur_str + set_list[now])
                visited[now] = False
            elif tail_char not in set_list[now][1:]:
                visited[now] = True
                DFS(cur_str + set_list[now])
                visited[now] = False

T = input()

for t in xrange(T):
    N = input()
    set_list = [zip_str(s) for s in raw_input().split()]

    if any([not isValid(s) for s in set_list]):
        print "Case #{0}: 0".format(t + 1)
        continue

    visited = [False for i in xrange(N)]
    cnt = 0
    DFS("")

    print "Case #{0}: {1}".format(t + 1, cnt)

