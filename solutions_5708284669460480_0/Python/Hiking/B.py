#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import collections

f_input = open(sys.argv[1])
problems = int(f_input.readline().rstrip())
for probnum in xrange(1, problems+1):
    K, L, S = map(int, f_input.readline().rstrip().split())
    keys = f_input.readline().rstrip()
    target = f_input.readline().rstrip()

    ## 深さ優先探索
    ## [出力なん文字目, [次はtargetのなん文字目], なん文字作ったか]
    result = collections.defaultdict(int)
    stack = [
        [0, [], 0]
    ]
    while stack:
        now_out, now_pointers, now_gotten = stack.pop()
        # print now_out, now_pointers, now_gotten
        for pointer in now_pointers:
            if pointer == L:
                now_gotten += 1
        if now_out == S:
            result[now_gotten] += 1
            continue

        now_pointers.append(0)
        for chara in keys:
            # ポインタ処理
            next_pointers = []
            for pointer in now_pointers:
                if pointer == L:
                    continue
                if target[pointer] == chara:
                    next_pointers.append(pointer+1)
            stack.append([now_out+1, next_pointers, now_gotten])

    need = max(result.keys())
    all_value = 0
    all_count = 0
    for key, value in result.items():
        all_value += key*value
        all_count += value
    print("Case #{}: {}".format(probnum, need-float(all_value)/all_count))
