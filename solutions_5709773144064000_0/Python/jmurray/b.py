import sys

for case in range(int(input())):
    c, f, x = list(map(float,input().split()))
    per_sec = 2.0
    seconds_so_far = 0
    answer = 1e99
    while True:
        guess = seconds_so_far + x/per_sec
        if guess > answer:
            break
        answer = guess
        seconds_so_far += c/per_sec
        per_sec += f
    print("Case #"+str(case+1)+": "+("%.7f"%answer))
