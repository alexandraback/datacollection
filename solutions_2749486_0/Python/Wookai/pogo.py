import sys

def generate_moves(limit = 100):
    positions = [[0,0,0, '']]
    moves_list = {}
    nb_seen = 0

    while positions:
        pos = positions.pop(0)
        index = '%d:%d' % (pos[0], pos[1])
        if index not in moves_list:
            path = pos[3]
            moves_list[index] = path
            nb_seen += 1
            next_jump = pos[2] + 1
            if pos[0] + next_jump <= limit:
                positions.append([pos[0] + next_jump, pos[1], next_jump, path+'E'])
            if pos[0] - next_jump >= -limit:
                positions.append([pos[0] - next_jump, pos[1], next_jump, path+'W'])
            if pos[1] + next_jump <= limit:
                positions.append([pos[0], pos[1] + next_jump, next_jump, path+'N'])
            if pos[1] - next_jump >= -limit:
                positions.append([pos[0], pos[1] - next_jump, next_jump, path+'S'])

    return moves_list


def process_case(moves_list):
    x, y = [int(k) for k in sys.stdin.readline().strip().split(' ')]
    index = '%d:%d' % (x, y)
    return moves_list[index]

def main():
    moves_list = generate_moves(100)
    T = int(sys.stdin.readline())
    for i in range(T):
        result = process_case(moves_list)
        print 'Case #%d: %s' % (i + 1, result)

if __name__ == '__main__':
    main()
