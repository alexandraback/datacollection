import sys

class DeceitfulWar():
    def __init__(self, naomi, ken):
        self.naomi = sorted(naomi)
        self.ken = sorted(ken)

    def solve(self):
        return self.deceitful(), self.war()

    def deceitful(self):
        naomi = list(self.naomi)
        ken = list(self.ken)
        points = 0
        useless_naomi = []
        for n in naomi:
            can_eat = False
            for k in ken:
                if n > k:
                    can_eat = True
                    break
            if not can_eat:
                useless_naomi.append(n)
        for i in range(len(useless_naomi)):
            ken.remove(max(ken))
        for u in useless_naomi:
            naomi.remove(u)
        pairs = []
        i = len(naomi) - 1
        j = len(naomi) - 1
        while i >= 0 and j >= 0:
            if naomi[i] > ken[j]:
                pairs.append((naomi[i], ken[j]))
                i -= 1
                j -= 1
            else:
                j -= 1
        points += len(pairs)
        return points

    def war(self):
        naomi = list(self.naomi)
        ken = list(self.ken)
        points = 0
        while len(naomi) > 0:
            chosen_naomi = max(naomi)
            chosen_ken = min(ken)
            for k in ken:
                if k > chosen_naomi:
                    chosen_ken = k
                    break
            naomi.remove(chosen_naomi)
            ken.remove(chosen_ken)
            if chosen_naomi > chosen_ken:
                points += 1
        return points

T = int(sys.stdin.readline())
for t in range(1, T + 1):
    N = int(sys.stdin.readline())
    naomi = [float(x) for x in sys.stdin.readline().split()]
    ken = [float(x) for x in sys.stdin.readline().split()]
    game = DeceitfulWar(naomi, ken)
    y, z = game.solve()
    print('Case #{0}: {1} {2}'.format(t, y, z))