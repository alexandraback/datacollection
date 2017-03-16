T = int(input())

def solve():
    S = input()
    curr = S[0]
    for char in S[1:]:
        if ord(char) >= ord(S[0]) and ord(char) >= ord(curr[0]):
            curr = char + curr
        else:
            curr = curr + char

    return curr

for t in range(T):
    print('Case #' + str(t+1) + ': ' + solve())
