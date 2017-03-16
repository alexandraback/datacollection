#include <iostream>
#include <map>
#include <vector>
#include <deque>
using namespace std;

class Node
{
public:
  Node* parent;
  long long value_processed;
  long long value_added;
  long long sum;
  Node(Node* p) { value_added = 0; sum = 0; parent = p; }
};

int main()
{
  int cases = 0;
  cin >> cases;
  for (int c = 1; c <= cases; c++)
  {
    cout << "Case #" << c << ":" << endl;
    int N = 0;
    cin >> N;
    map<long long, Node*> sums;
    Node root(0);
    deque<Node*> pending_node;
    pending_node.push_back(&root);
    Node* match_found = 0;
    for (int i = 1; i <= N; i++)
    {
      long long value = 0;
      cin >> value;
      if (match_found != 0)
        continue;
      while (pending_node.size() > 0 && pending_node.front()->value_processed != value)
      {
        Node* add_value = new Node(pending_node.front());
        add_value->value_processed = value;
        add_value->value_added = value;
        add_value->sum = value + add_value->parent->sum;
        if (sums.count(add_value->sum))
        {
          match_found = add_value;
          break;
        }
        else
        {
          sums[add_value->sum] = add_value;
          pending_node.push_back(add_value);
        }
        Node* skip_value = new Node(pending_node.front());
        skip_value->value_processed = value;
        skip_value->value_added = 0;
        skip_value->sum = skip_value->parent->sum;
        pending_node.push_back(skip_value);
        pending_node.pop_front();
      } // while pending
    } // for N
    if (match_found == 0)
      cout << "Impossible" << endl;
    else
    {
      Node* current = sums[match_found->sum];
      deque<long long> result_one;
      while (current->parent != 0)
      {
        if (current->value_added > 0)
          result_one.push_front(current->value_added);
        current = current->parent;
      }
      current = match_found;
      deque<long long> result_two;
      while (current->parent != 0)
      {
        if (current->value_added > 0)
          result_two.push_front(current->value_added);
        current = current->parent;
      }
      for (int k = 0; k < result_one.size(); k++)
        cout << result_one[k] << " ";
      cout << endl;
      for (int k = 0; k < result_two.size(); k++)
        cout << result_two[k] << " ";
      cout << endl;
    }
  }
  return 0;
}


      

