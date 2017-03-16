#!/usr/bin/python

t = int(raw_input())

for i in range(t):
    val = raw_input()
    bool_arr = [(val[j] == '+') for j in range(len(val))]
    ans = 0
    while not all(bool_arr):
        start = val.find('-')
        end = val.find('+', start)
        if start == 0:
            ans += 1
        else:
            ans += 2

        if end == -1:
            val = val.replace('-', '+')
        else:
            val = val[:start] + ('+' * (end - start)) + val[end:]
        
        bool_arr = [(val[j] == '+') for j in range(len(val))]
    print "Case #" + str(i + 1) + ": " + str(ans)
