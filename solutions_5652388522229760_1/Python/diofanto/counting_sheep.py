def update_digits_seen(n, num_digits_to_see, digits_to_see):
    for d in str(n):
        d = int(d)
        if digits_to_see[d]:
            digits_to_see[d] = False
            num_digits_to_see -= 1
    return num_digits_to_see

def count(n):
    if n == 0:
        return "INSOMNIA"
    cnt = 1
    nn = n
    num_digits_to_see = 10
    digits_to_see = [True] * 10
    while True:
        num_digits_to_see = update_digits_seen(nn, num_digits_to_see, digits_to_see)
        if num_digits_to_see == 0:
            return nn
        cnt += 1
        nn = n * cnt

for t in range(int(input())):
    print("Case #{0}: {1}".format(t+1, count(int(input()))))
