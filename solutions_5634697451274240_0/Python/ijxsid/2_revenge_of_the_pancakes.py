from time import sleep

def flip_at(state, pos):
    new_state = state[pos:]
    prefix = state[:pos][::-1].translate(str.maketrans('-+', '+-'))
    return prefix + new_state

def min_flips(start):
    seen_states = {}
    final = start.replace('-', '+')
    fringe = [(0, start)]
    l = len(start)
    current = fringe[0]
    level = current[0]
    max_level = None
    if(start == final):
        return 0
    while (max_level is None or level <= max_level) and (fringe != []):
        seen_states[current[-1]] = 1
        level = current[0] + 1
        for pos in range(1, l + 1):
            nxt = flip_at(current[-1], pos)
            if nxt not in seen_states:
                fringe.append((level, nxt))
                if nxt == final:
                    if max_level is None:
                        max_level = level
                    else:
                        if level < max_level:
                            max_level = level

        fringe.pop(0)
        if fringe != []:
            current = fringe[0]
            level = current[0]
    return max_level if max_level is not None else 0

def main():
    T = int(input().strip())
    for t in range(T):
        S = input().strip()
        ans = min_flips(S)
        print('Case #{n}: {ans}'.format(n=t + 1, ans=ans))

if __name__ == '__main__':
    main()
