#include<iostream>
#include<iomanip>
#include<list>
#include<algorithm>
using namespace std;

  

class node
{
public:
  int startval;
  int endval;

  bool contains(int v)
  {
    if((startval <= v) && (endval >= v))
      {
	return true;
      }
    return false;
  }

  bool issuperset(node* p)
  {
    if((startval <= p->startval) && (endval >= p->endval))
      {
	return true;
      }
    return false;
  }

};



class range
{
public :
  list<node> rlist;
  int min;
  int max;

  //to be called after min and max are set.
  void initialize()
  {
    node t;
    t.startval = min;
    t.endval = max;
    rlist.push_back(t);
  }

  void printranges()
  {
    list<node>::iterator itr;
    for(itr = rlist.begin();itr != rlist.end();itr++)
      {
	cout<<(*itr).startval<<" "<<(*itr).endval<<endl;
      }

  }

  void andinterval(node t)
  {
    list<node>::iterator itr;

    for(itr = rlist.begin();itr != rlist.end();itr++)
      {

 	//checking for no-intersection-possible-any-further.
	if(t.endval < (*itr).startval)
	  {
	    return;
	  }

	if((*itr).issuperset(&t))
	  {
	    (*itr) = t;
	    return;
	  }

	if((*itr).contains(t.startval))
	  {
	    (*itr).startval = t.startval;
	  }
	
	if((*itr).contains(t.endval))
	  {
	    (*itr).endval = t.endval;
	  }
      }
    return;
  }


  //min to l and r to max
  void removeinterval(node t)
  {
    list<node>::iterator itr;

    for(itr = rlist.begin();itr != rlist.end();itr++)
      {


 	//checking for no-intersection-possible-any-further.
	if((*itr).startval  > t.endval)
	  {
	    return;
	  }

	//no effect condition.
	if((*itr).endval < t.startval)
	  {
	    continue;
	  }

	//remove all intervals that are subsets of t
	if(t.issuperset(&(*itr)))
	  {
	    rlist.erase(itr);
	    continue;
	  }

	//contains condition. have to break the node into two.
	if((*itr).issuperset(&t))
	  {
	    node temp;
	    temp.startval = (*itr).startval;
	    temp.endval = t.startval;
	    (*itr).startval = t.endval;
	    rlist.insert(itr,temp);
	    return;
	  }

	if((*itr).contains(t.startval))
	  {
	    (*itr).endval = t.startval;
	  }

	if((*itr).contains(t.endval))
	  {
	    (*itr).startval = t.endval;
	  }
      }
  }
};

	    




main()
{

  node t;
  t.startval = 10;
  t.endval = 20;
  range r;
  r.min = 0;
  r.max = 50;
  r.initialize();
  r.removeinterval(t);
  t.startval = 25;
  t.endval = 30;
  r.removeinterval(t);
  r.printranges();

}
