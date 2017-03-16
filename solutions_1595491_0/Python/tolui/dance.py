'''
Created on Apr 14, 2012

@author: disqiu
'''
def vote(tot_vote,p):
    rest = tot_vote%3
    max_vote = tot_vote/3
    
    if rest!=0:
        max_vote+=1
    
    if max_vote >= p:
        return (3,1) # to say that it is already more than p
    else:
        return (rest,max_vote-p)