def path_to_index(vertices, K):
    if len(vertices) == 1:
        return vertices[0]
    else:
        return K * path_to_index(vertices[:-1], K) + vertices[-1]

def get_output(K, C, S):
    if C * S < K:
        return "IMPOSSIBLE"
    # if task is not impossible, construct paths along
    # tree defining construction of this artwork
    current = 0
    indices = []
    while current < K:
        new_path = list(range(current, min([K, current+C])))
        if len(new_path) < C:
            new_path = new_path + [new_path[-1]] * (C - len(new_path))
        indices.append(path_to_index(new_path, K)+1)
        current = new_path[-1] + 1
    return " ".join([str(n) for n in indices])


if __name__ == "__main__":
    T = int(input())
    for k in range(T):
        K, C, S = [int(s) for s in input().split()]
        print("Case #{0}: {1}".format(k+1, get_output(K, C, S)))
