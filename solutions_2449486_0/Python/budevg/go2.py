
def read_next_grass_pattern():
    pattern = []
    n, m = [int(e) for e in (raw_input().split())][:2]
    for i in range(n):
        raw = [int(e) for e in (raw_input().split())][:m]
        pattern.append(raw)
    return pattern

def get_grass_heights(pattern):
    heights = set()
    for row in pattern:
        for height in row:
            heights.add(height)
    return sorted(list(heights))

def lawnmower_path_enumerate(n , m):
    for i in range(n):
        yield [(i,k) for k in range(m)]
    for j in range(m):
        yield [(k,j) for k in range(n)]

def is_possible_path(height, path, pattern):
    return all(pattern[x][y] <= height for x,y in path)

def mark_path(height, path, pattern):
    for x,y in path:
        pattern[x][y] = height

def check_height_and_mark(height, next_height, pattern):
    # the algorithm will first check if the lowest height of grass
    # can be created using lawnmover. If this is the case we can recursively
    # solve the problem by assuming that the lowest grass height is
    # the same as the next lowes height
    possible_paths = []
    for path in lawnmower_path_enumerate(len(pattern), len(pattern[0])):
        if is_possible_path(height, path, pattern):
            possible_paths.append(path)

    for possible_path in possible_paths:
        mark_path(next_height, possible_path, pattern)

    for row in pattern:
        if not all(elem >= next_height for elem in row):
            return False
    return True

def is_grass_pattern_possible(pattern):
    heights = get_grass_heights(pattern)
    if len(heights) < 2:
        return True
    for i in range(len(heights)-1):
        height = heights[i]
        next_height = heights[i+1]
        if not check_height_and_mark(height, next_height, pattern):
            return False
    return True

def main():
    num_of_cases = int(raw_input())
    for i in range(num_of_cases):
        pattern = read_next_grass_pattern()
        if is_grass_pattern_possible(pattern):
            print "Case #%d: YES" % (i+1, )
        else:
            print "Case #%d: NO" % (i+1, )

    pass


if __name__ == '__main__':
    main()
