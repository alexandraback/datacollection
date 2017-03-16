
sample = "sample"
small = "C-small-attempt3"
large = "C-large"
current = small

fin = open(current + ".in", "r")
fout = open(current + ".out", 'w')
# f1out = open(current + "1.out", 'w')
# f2out = open(current + "2.out", 'w')

T = int(fin.readline())

q_order = {'i':-1, 'j':0, 'k':1}
q_next = {'i':'j', 'j':'k', 'k':'i'}

class Quaternion:

    def __init__(self, sign, v):
        self.sign = sign
        self.v = v

    def qorder(self):
        return q_order[self.v]
    def qnext(self):
        return Quaternion(self.sign, q_next[self.v])

    def __mul__(self, other):
        sign = not (self.sign ^ other.sign)

        if self.v == '1':
            return Quaternion(sign, other.v)
        if other.v == '1':
            return Quaternion(sign, self.v)
        if self.v == '0' or other.v == '0':
            return Quaternion(sign, '0')

        if self.v == other.v:
            return Quaternion( not (sign ^ False), '1')

        if self.qnext().v == other.v:
            return Quaternion(sign, other.qnext().v)
        else:
            return Quaternion( not (sign ^ False), self.qnext().v)

        print 'ERROR'

    def __neg__(self):
        return Quaternion(not (self.sign ^ False), self.v)

    def __eq__(self, other):
        # if other == 1:
        #     return self.sign == True and self.v == '1'
        # elif other == -1:
        #     return self.sign == False and self.v == '1'

        return self.sign == other.sign and self.v == other.v

    def __repr__(self):
        sign = '+' if self.sign else '-'
        return sign + self.v

def q(s):
    return Quaternion(True, s)

def mult(qs):
    r = q('1')
    for vq in qs:
        r = r * vq
    return r

def mult_table(table, vs, a, b, indices):
    key = str(a) + ',' + str(b)
    if table.has_key(key):
        return table[key]
    else:
        cs = [x for x in indices if a < x < b]
        if not cs:
            value = mult(vs[a:b])
        else:
            c = cs[len(cs)/2]
            value = mult_table(table, vs, a, c, indices) * mult_table(table, vs, c, b, indices)
            #print key, value, a, c, b
        table[key] = value
        return value

# def mult_table(vs, sorted_indices):
#     table = {}
#     for ii in len(sorted_indices):
#         prev = -ii
#         for ji in sorted_indices:
#             if prev > 0:
#
#                 prev = ji
#             else:
#                 prev += 1

#print q('i') * q('j'), q('j') * q('k'), q('i') * q('j') * q('k')
def solve(L, X, ijk):
    fqs = []
    for i in ijk:
        if i == 'i' or i == 'j' or i == 'k':
            fqs.append(q(i))
    qs = []
    extend = X#min(X, 4)
    for i in range(extend):
        qs.extend(fqs)


    print qs
    lq = q('1')
    left_plus = []
    left_minus = []
    for i_l, l in enumerate(qs):
        # print lq, l
        lq = nx = lq * l
        if nx == q('i'):
           left_plus = [i_l+1, nx, l]
        if nx == -q('i'):
            left_minus = [i_l+1, nx, l]
        if left_plus and left_minus:
            break

    right_plus = []
    right_minus = []
    rq = q('1')
    for i_r, r in enumerate(reversed(qs)):
        rq = nx = r * rq
        if nx == q('k'):
            right_plus = [i_r+1, nx, r]
        elif nx == -q('k'):
            right_minus = [i_r+1, nx, r]
        if right_plus and right_minus:
            break

    if (not left_plus) and not left_minus:
        return "NO"
    if not right_plus and not right_minus:
        return "NO"

    dqs = []
    for idqs in range(X): #range(min(X, 8)):
        dqs.extend(fqs)

    lefts = []
    rights = []

    mc = {}
    mfqs = mult(fqs)
    indices = []
    if left_plus:
        indices.append(left_plus[0])
        lefts.append(left_plus)
    if left_minus:
        indices.append(left_minus[0])
        lefts.append(left_minus)
    if right_plus:
        indices.append(len(dqs) - right_plus[0])
        rights.append(right_plus)
    if right_minus:
        indices.append(len(dqs) - right_minus[0])
        rights.append(right_minus)
    for ie in range(8):
        index = ie * len(fqs)
        indices.append(index)
        mc[str(index) + ',' + str(index + len(fqs))] = mfqs
    sorted_indices = sorted(set(indices))

    # prev = -1
    # mc = mult_table(qs, sorted_indices)
    # for ii in sorted_indices:
    #     for ij in sorted_indices[]:
    #         if
    #     if prev > 0
    #         mc[[prev, index]] = mult(qs[prev:index+1])
    #     prev = index


    print mc, sorted_indices
    for j_l in lefts:
        for j_r in rights:
            if j_l[0] + j_r[0] < len(dqs) + 2:
                #isj = mult_table(mc, dqs, j_l[0]+1, len(dqs)-j_r[0]-1, sorted_indices)
                isj = mult(dqs[j_l[0] : len(dqs) - j_r[0] ])
                #print j_l[1], isj, j_r[1], j_l[1] * isj * j_r[1]
                if j_l[1] * isj * j_r[1] == -q('1'):
                    return "YES"

    return "NO"

for i in range(T):
    L, X = map(int, fin.readline().split())
    ijk = fin.readline()
    solution = solve(L, X, ijk)
    # if solution > candidate:
    #     print 'ERROR', i + 1, solution, candidate
    # if solution != solution1:
    #     print 'ERROR', i + 1, solution, solution1, candidate
    answer = "Case #%d: %s\n" % (i + 1, solution)
    print answer
    fout.write(answer)

fin.close()
fout.close()
# f1out.close()
# f2out.close()