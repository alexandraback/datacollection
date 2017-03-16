n = int(input())

def check_rows(lawn):
    for row in lawn:
        maximum = max(row)[0]
        for tile in row:
            if tile[0] == maximum:
                tile[1] = True

def do_case():
    height, width = map(int, input().split())
    lawn = [] #[y][x]
    for y in range(height):
        lawn.append([[int(i), False] for i in input().split()])
    check_rows(lawn)
    lawn = list(zip(*lawn)) #transpose
    check_rows(lawn)
    return all(map(all, [[j[1] for j in i] for i in lawn]))


for i in range(n):
    response = do_case()
    print("Case #{}: {}".format(i+1, ("NO", "YES")[response]))
