from time import sleep

def flip_at(state, pos):
    new_state = state[pos:]
    prefix = state[:pos][::-1].translate(str.maketrans('-+', '+-'))
    return prefix + new_state

def min_flips(start, flips):
    current = start
    if len(current) == 0 or current == '+'*len(current):
        return flips
    if current[-1] == '-':
        if current[0] == '+':
            t = 0
            while ((t < len(current) - 1) and (current[t] == '+')):
                t += 1
            current = flip_at(current, t)
            flips += 1
        current = flip_at(current, len(current))
        flips += 1
    rev_current = current[::-1]
    i = 0
    while ((i < len(rev_current) - 1) and (rev_current[i] != '-')):
        i += 1
    rev_current = rev_current[i:]
    current = rev_current[::-1]
    return min_flips(current, flips)


def main():
    T = int(input().strip())
    for t in range(T):
        S = input().strip()
        ans = min_flips(S, 0)
        print('Case #{n}: {ans}'.format(n=t + 1, ans=ans))

if __name__ == '__main__':
    main()
