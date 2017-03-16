#!/usr/bin/python3
# -*- coding: utf-8 -*-

class Solver:
    def __init__(self):
        self.K,self.N = map(int,input().split())
        self.k = list(map(int,input().split()))
        self.orig_k = list(self.k)
        self.types = [0 for _ in range(self.N)]
        self.opens = [False for _ in range(self.N)]
        self.keys = [[] for _ in range(self.N)]
        self.bytypes = [[] for _ in range(210)]
        for i in range(self.N):
            self.types[i],Ki,*self.keys[i] = map(int,input().split())
            assert Ki==len(self.keys[i])
            self.bytypes[self.types[i]].append(i)
        self.ans = []

    def open(self,n):
        assert not self.opens[n]
        self.opens[n] = True
        self.k.remove(self.types[n])
        self.k += self.keys[n]
        self.ans.append(n)

    def find_cycle(self,t,start_t=None,useds=None):
        if t==start_t:
            return []
        if start_t is None:
            start_t = t
        if useds is None:
            useds = [False for _ in range(210)]
        if useds[t]:
            return
        useds[t] = True
        for n in self.bytypes[t]:
            if self.opens[n]:
                continue
            for key in self.keys[n]:
                res = self.find_cycle(key,start_t,useds)
                if res is not None:
                    return [n] + res

    def clear_cycles(self):
        has_cycle = True
        while has_cycle:
            has_cycle = False
            for key in set(self.k):
                res = self.find_cycle(key)
                if res:
                    has_cycle = True
                    for n in res:
                        self.open(n)

    def open_other(self):
        has = True
        while has:
            has = False
            self.clear_cycles()
            old_keys = list(self.k)
            for key in old_keys:
                for n in self.bytypes[key]:
                    if not self.opens[n]:
                        self.open(n)
                        has = True
                        break
                if has:
                    break

    def true_solve(self):
        cur_k = list(self.k)
        cur_opens = list(self.opens)
        self.open_other()
        if False in self.opens:
            return
        self.k = list(cur_k)
        self.opens = list(cur_opens)
        ans = []
        for _ in range(self.N):
            for n in range(self.N):
                if self.opens[n]:
                    continue
                if self.types[n] not in self.k:
                    continue
                cur_k = list(self.k)
                cur_opens = list(self.opens)
                self.open(n)
                self.open_other()
                self.k = cur_k
                cur_opens,self.opens = self.opens,cur_opens
                if False not in cur_opens:
                    self.open(n)
                    ans.append(n)
                    break
            else:
                assert False
        return ans

    def calc(self,n,mask=0):
        if False not in self.cur_opens:
            return True
        if self.cur_opens[n]:
            return False
        if self.types[n] not in self.cur_keys:
            return False
        mask += 2**n
        if self.masks[mask]:
            return False
        self.queue.append(n)
        self.cur_opens[n] = True
        self.masks[mask] = True
        old_keys = self.cur_keys
        self.cur_keys = list(self.cur_keys)
        self.cur_keys.remove(self.types[n])
        self.cur_keys += self.keys[n]
        for i in range(self.N):
            if self.calc(i,mask):
                return True
        self.cur_opens[n] = False
        self.cur_keys = old_keys
        self.queue.pop()
        return False

    def solve2(self):
        self.cur_keys = list(self.k)
        self.cur_opens = [False for _ in range(self.N)]
        self.queue = []
        self.masks = [False for _ in range(2**self.N)]
        for i in range(self.N):
            if self.calc(i):
                return self.queue

    def check(self,ans):
        if ans is None:
            return
        k = list(self.orig_k)
        assert len(ans)==self.N
        assert len(set(ans))==self.N
        for n in ans:
            k.remove(self.types[n])
            k += self.keys[n]

    def solve(self):
        ans = self.solve2()
        #self.check(res2)
        #ans = self.true_solve()
        #assert res2 == ans,(res2,ans)
        if ans is None:
            print ("IMPOSSIBLE")
        else:
            print (" ".join([str(x+1) for x in ans]))

def solve():
    Solver().solve()

if __name__=="__main__":
    T = int(input())
    for t in range(1,T+1):
        print("Case #%d:"%t,end=' ')
        solve()

