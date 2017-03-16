def main_code(x):
    pancakes = input() + "+"
    flips = 0
    last = pancakes[0]
    for c in pancakes:
        if c != last:
            last = c
            flips += 1
    print("Case #" + str(x + 1) + ":", flips)

T = int(input())
for x in range(T):
    main_code(x)
