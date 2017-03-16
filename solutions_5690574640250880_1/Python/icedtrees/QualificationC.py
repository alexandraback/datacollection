import sys

def square(height, width):
    return [["."] * width for row in range(height)]

def valid_solution(height, width, mines):
    size = height * width
    spaces = size - mines
    
    grid = [["*"] * width for row in range(height)]

    if spaces == 1:
        pass
    elif spaces < width * 2: # not enough to fill two rows
        if height == 1:
            grid[0][:spaces] = ["."] * spaces
        elif spaces % 2 == 0: # divide into two rows
            if spaces == 2:
                return False
            if height < 2:
                return False
            length = spaces // 2
            grid[0][:length], grid[1][:length] = square(2, length)
        else: # fill two rows then shift last three up
            if height < 3:
                return False
            rowSize = (spaces - 3) // 2
            if rowSize < 3:
                return False
            grid[0][:rowSize], grid[1][:rowSize] = square(2, rowSize)
            grid[2][:3] = ["."] * 3
    elif spaces % width == 1: # that one poor guy
        filledRows = spaces // width
        if filledRows == 2:
            if width < 4:
                return False
            grid[0][:width - 1], grid[1][:width - 1] = square(2, width - 1)
            grid[2][:3] = ["."] * 3
        else:
            if width < 3:
                return False
            grid[:filledRows - 1] = square(filledRows - 1, width)
            grid[filledRows - 1] = ["."] * (width - 1) + ["*"]
            grid[filledRows][:2] = ["."] * 2
    else: # fill ALL the rows!
        filledRows = spaces // width
        overhang = spaces % width
        grid[:filledRows] = square(filledRows, width)
        if overhang:
            grid[filledRows][:overhang] = ["." * overhang]
        
    grid[0][0] = "c"
    return grid

cases = int(raw_input())
for case in range(1, cases + 1):
    height, width, mines = map(int, raw_input().split())
    # print("Case #{}: height-{} width-{} spaces-{}".format(case, height, width, height*width-mines))
    print("Case #{}:".format(case))
    grid = valid_solution(height, width, mines)
    if grid:
        # assert(sum([len([char for char in row if char == "*"]) for row in grid]) == mines)
        print("\n".join(map("".join, grid)))
    else:
        print("Impossible")