import collections
import copy

class Possibilities(object):

    def __init__(self, kids):
        self.p = [(0, range(1, kids + 1))]


def circle_size(bff_map):

    possibilities = [({}, list(range(1, len(bff_map))))]  # circle state, options
    best_so_far = 0

    while possibilities:
        if best_so_far == len(bff_map) - 1:
            # Maximum circle size reached; break early
            return best_so_far

        # Get the next possibility and reset the circle to that state.
        circle, options = possibilities.pop()
        next_kid = options.pop()

        if options:
            # Put the other options back.
            possibilities.append((copy.deepcopy(circle), options))

        # print('='*50)
        # print('Trying', next_kid, ' in circle ',
        #       list(sorted(circle.items(), key=lambda t:t[1])))

        # Put the next kid in the circle.
        circle[next_kid] = len(circle)

        # Add bff chain until cycle or we get stuck.
        id = next_kid; pos = len(circle)
        while True:
            bff = bff_map[id]
            if bff in circle:
                bff_pos = circle[bff]
                # print(id, 'found bff ', bff, 'in circle')
                if bff_pos == 0 and len(circle) >= 3:
                    # print('case 1')
                    # the bff is the first position; circle is closed
                    best_so_far = max(best_so_far, len(circle))
                    break
                elif 0 < bff_pos < pos - 2:
                    # print('case 2')
                    # the bff is already sitting and not next to them; impossible
                    break
                else:
                    # print('case 3')
                    # They are both bffs, the next person can be any of the remaining
                    remain = [i for i in range(1, len(bff_map)) if i not in circle]
                    if not remain:
                        return len(circle)
                    possibilities.append((copy.deepcopy(circle), remain))
                    break
            else:
                circle[bff] = pos  # put friend right next to us
            id = bff; pos += 1

    return best_so_far


INPUT = 'c-small0.in'

with open(INPUT) as f:
    lines = f.read().split('\n')

cases = int(lines[0])
i = 1
for c in range(1, cases+1):
    kids = int(lines[i])
    bff_map = [-1]
    for bff in lines[i+1].split(' '):
        bff_map.append(int(bff))
    # print('solution: ', circle_size(bff_map))
    print('Case #{0}: {1}'.format(c, circle_size(bff_map)))
    i += 2
    # print('-'*50)