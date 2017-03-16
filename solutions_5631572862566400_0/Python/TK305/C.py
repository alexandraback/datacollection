class Bffcircle():
    def __init__(self, cur_circle, bff, n):
        self.cur_circle, self.bff, self.n = cur_circle, bff, n

    def extensions(self):
        bff, cur_circle = self.bff, self.cur_circle
        current_child = cur_circle[-1]
        tot_ext = []

        if bff[current_child-1] not in cur_circle:
            new_bff = bff[current_child-1]
            if (bff[new_bff-1] not in cur_circle) or bff[new_bff-1] == current_child or bff[new_bff-1] == cur_circle[0]:
                tot_ext.append(Bffcircle(cur_circle[:] + [new_bff], bff, self.n+1))
        elif bff[current_child-1] == cur_circle[-2]:
            for i in range(len(bff)):
                if bff[i] == current_child and (i+1 not in cur_circle):
                    tot_ext.append(Bffcircle(cur_circle[:] + [i+1], bff, self.n+1))
        return tot_ext


if __name__ == "__main__":
    with open("C-small-attempt4.in", 'r') as inputf:
        outputf=open("C-small-4.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            line = inputf.readline().rstrip('\n')
            n = int(line)
            line = inputf.readline().rstrip('\n')
            bff = [int(item) for item in line.split(' ')]
            cur_max = 0
            stack = []

            for child in range(1, n+1):
                stack.append(Bffcircle([child], bff, 1))

            while stack:
                cur_node = stack.pop()
                cur_extensions = cur_node.extensions()
                if cur_extensions:
                    for child in cur_extensions:
                        stack.append(child)

                if cur_node.n > cur_max:
                    max_circle = cur_node.cur_circle
                    last_bff = bff[max_circle[-1]-1]
                    if ((len(max_circle) > 2 and last_bff == max_circle[-2]) or last_bff == max_circle[0]):
                        cur_max = cur_node.n

            result = "Case #{0}: {1}".format(i, cur_max)
            outputf.write(result)

            if i < test_num:
                outputf.write("\n")