def solve():
    b, m = [int(i) for i in input().split()]
    if m > 2**(b-2):
        return "IMPOSSIBLE"
    else:
        graph = construct(b)
        rep = bin(m)[2:][::-1]
        if m == 2**(b-2):
            for key in graph:
                if key != b-1:
                    graph[key].append(b-1)
        else:
            for i, digit in enumerate(rep):
                if digit == "1":
                    graph[i+1].append(b-1)

        res = ["POSSIBLE"]
        
        for i in range(b):
            row = []
            for j in range(b):
                if j in graph[i]:
                    row.append(1)
                else:
                    row.append(0)
            res.append(''.join(str(x) for x in row))
        return '\n'.join(res)
        

def construct(b):
    d = {i:list(range(i+1,b-1)) for i in range(b) }
    return d
        
    


n_cases = int(input())

for n_case in range(n_cases):
    print("Case #{}: {}".format(n_case+1, solve()))
