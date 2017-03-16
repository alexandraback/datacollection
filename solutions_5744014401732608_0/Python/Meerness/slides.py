__author__ = 'User'



def make_grid(B, M):
    if M > 2**(B-2):
        return "IMPOSSIBLE\n"
    output = "POSSIBLE\n"
    grid = [["0"]*B for _ in range(B)]
    for row in range(B):
        for col in range(B):
            if col > row:
                grid[row][col] = "1"
    paths_to_remove = 2**(B-2) - M
    binary_counter = 2**(B-3)
    counter = B - 1
    while binary_counter > 0 and paths_to_remove > 0:
        if paths_to_remove >= binary_counter:
            paths_to_remove -= binary_counter
            grid[counter - 1][B - 1] = "0"
        counter -= 1
        binary_counter //= 2
    for row in range(B):
        output += "".join(grid[row])
        output += "\n"
    return output

with open("file_name.txt", "r") as file:
    with open("result.txt", "w") as write_file:
        for i, line in enumerate(file):
            if i == 0:
                continue
            input_list = line.strip().split(' ')
            x = make_grid(int(input_list[0]), int(input_list[1]))
            write_file.write("Case #" + str(i) + ": " + x)