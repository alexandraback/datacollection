from collections import deque

def inverse_top(stack, i):
    return tuple(1 - x for x in reversed(stack[:i])) + stack[i:]

def get_distances(n):
    source = (1,)*n
    result = {source: 0}
    todo = deque([source])
    while todo:
        stack = todo.popleft()
        for i, _ in enumerate(stack):
            s = inverse_top(stack, i + 1)
            if s not in result:
                result[s] = result[stack] + 1
                todo.append(s)
    return result

dist = get_distances(10)
answer = 'Case #{}: {}'
n_tests = int(input())
for i in range(n_tests):
    stack = tuple(1 if c == '+' else 0 for c in input())
    stack += (1,)*(10 - len(stack))
    print(answer.format(i + 1, dist[stack]))
