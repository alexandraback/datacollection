import collections

def solve(input_str):
    chars = list(input_str)
    result = collections.deque([])
    for ch in chars:
        if len(result) == 0:
            result.append(ch)
        elif ch >= result[0]:
            result.appendleft(ch)
        else:
            result.append(ch)
        # print(result)
    return ''.join(result)

file = open('input1b')
lines = file.readlines()

index = 0
for line in lines:
    if index != 0:
        s = line.strip()
        if len(s) == 0:
            continue
        answer = solve(s)
        print('Case #%d: %s' % (index, answer))
    index += 1

"""
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE

Case #1: CAB
Case #2: MJA
Case #3: OCDE
Case #4: BBAAA
Case #5: CCCABBBAB
Case #6: CCCBAABAB
Case #7: ZXCASDQWE
"""